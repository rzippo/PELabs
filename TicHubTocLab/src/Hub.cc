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

#include "Hub.h"

namespace tictoclab {

Define_Module(Hub);

void Hub::initialize()
{
    inSize = gateSize("in");
    outSize = gateSize("out");
}

void Hub::handleMessage(cMessage *msg)
{
    int in_index = msg->getArrivalGate()->getIndex();
    send(msg, "out", (in_index + 1) % outSize);
}

} //namespace
