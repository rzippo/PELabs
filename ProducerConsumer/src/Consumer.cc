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

#include "Consumer.h"
#include "ConsumerRequest_m.h"
#include "ProducerResponse_m.h"

Define_Module(Consumer);

void Consumer::initialize()
{
    id = par("id");
    period = par("period");

    periodicSend = new cMessage("Periodic send");
    scheduleAt(simTime(), periodicSend);

    //Signal setup
    responseReceivedSignal = registerSignal("responseReceived");
}

void Consumer::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        //Send scheduled request

        ConsumerRequest* request = new ConsumerRequest("Consumer request");
        request->setConsumerID(id);
        request->setSentTimestamp(simTime());
        send(request, "out");

        //Schedule next message

        scheduleAt(simTime() + period, periodicSend);
    }
    else
    {
        //Handle producer response
        ProducerResponse* resp = static_cast<ProducerResponse*>(msg);

        simtime_t responseTime = simTime() - resp->getRequest()->getSentTimestamp();
        emit(responseReceivedSignal, responseTime);

        delete resp->getRequest();
        delete resp;
    }
}
