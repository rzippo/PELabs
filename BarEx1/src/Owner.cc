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

#include "Owner.h"

Define_Module(Owner);

void Owner::initialize()
{
    TimeBetweenReceptionSignal = registerSignal("TimeBetweenReception");
    lastMessageTime = simTime();
}

void Owner::handleMessage(cMessage *msg)
{
    //EV << "Order received" << endl;
    emit(TimeBetweenReceptionSignal,
            ((double)(simTime() - lastMessageTime).inUnit(SimTimeUnit::SIMTIME_MS)) / 1000);
    lastMessageTime = simTime();

    delete msg;
}
