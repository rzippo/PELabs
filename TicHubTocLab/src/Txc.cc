//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Txc.h"

namespace tictoclab {

Define_Module(Txc);

void Txc::initialize()
{
    counter = 0;

    msgSeenSignal = registerSignal("msgSeen");
    responseTimeSignal = registerSignal("responseTimeValue");

    lastSent = 0;

    if (par("sendInitialMessage").boolValue())
    {
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

void Txc::handleMessage(cMessage *msg)
{
    // just send back the message we received
    if(par("modelProcessingTime"))
    {
        if(msg->isSelfMessage())
        {
            send(msg, "out");
            emit(responseTimeSignal, simTime() - lastSent);
            lastSent = simTime();
        } else
        {
            emit(msgSeenSignal, 1);

            counter++;
            EV << counter << endl;
            if(par("procTimeSet"))
            {
                scheduleAt(simTime() + par("procTime"), msg);
            }
            else
            {
                double time = uniform(0,5);
                scheduleAt(simTime() + time, msg);
            }
        }
    }
    else
    {
        emit(msgSeenSignal, 1);
        send(msg, "out");
        emit(responseTimeSignal, simTime() - lastSent);
        lastSent = simTime();
    }
}

}; // namespace
