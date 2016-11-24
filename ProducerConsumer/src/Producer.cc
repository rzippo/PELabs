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

#include "Producer.h"
#include "ProducerResponse_m.h"

Define_Module(Producer);

void Producer::initialize()
{
    //Nothing to do here
}

void Producer::handleMessage(cMessage *msg)
{
    if(!msg->isSelfMessage())
    {
        //Computed response will be ready to send later
        ProducerResponse* response = new ProducerResponse("Producer response");
        response->setRequest(static_cast<ConsumerRequest*>(msg));
        scheduleAt(simTime() + par("processingTime"), response);
    }
    else
    {
        //Response is now computed and ready to send
        send(msg, "out");
    }
}
