//
// Generated file, do not edit! Created by nedtool 5.0 from ProducerResponse.msg.
//

#ifndef __PRODUCERRESPONSE_M_H
#define __PRODUCERRESPONSE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "ConsumerRequest_m.h"
typedef ConsumerRequest* ConsumerRequestPointer;
// }}

/**
 * Class generated from <tt>ProducerResponse.msg:32</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * message ProducerResponse
 * {
 *     ConsumerRequestPointer request;
 * }
 * </pre>
 */
class ProducerResponse : public ::omnetpp::cMessage
{
  protected:
    ConsumerRequestPointer request;

  private:
    void copy(const ProducerResponse& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ProducerResponse&);

  public:
    ProducerResponse(const char *name=nullptr, int kind=0);
    ProducerResponse(const ProducerResponse& other);
    virtual ~ProducerResponse();
    ProducerResponse& operator=(const ProducerResponse& other);
    virtual ProducerResponse *dup() const {return new ProducerResponse(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual ConsumerRequestPointer& getRequest();
    virtual const ConsumerRequestPointer& getRequest() const {return const_cast<ProducerResponse*>(this)->getRequest();}
    virtual void setRequest(const ConsumerRequestPointer& request);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ProducerResponse& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ProducerResponse& obj) {obj.parsimUnpack(b);}


#endif // ifndef __PRODUCERRESPONSE_M_H

