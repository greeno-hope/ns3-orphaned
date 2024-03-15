/*
 *  Copyright (c) 2024 Liverpool Hope University, UK
 *
 *  Authors:
 *      Mark Greenwood
 *      Nathan Nunes
 *
 *  File: ospf-l4-protocol.h
 *
 *  Represents the OSPF protocol.
 *
 *  MRG: In ns3 any protocol that uses IPv4 as its transport layer extends
 *  the IpL4Protocol class which contains a lot of the obvious plumbing
 *  for inserting into a node and connecting to the underlying network layer
 *
 */

#ifndef OSPF_L4_PROTOCOL_H
#define OSPF_L4_PROTOCOL_H

#include "ip-l4-protocol.h"
#include "ipv6-end-point-demux.h"

#include "ns3/packet.h"
#include "ns3/ptr.h"

#include <stdint.h>
#include <unordered_map>

namespace ns3 {

// Forward class declarations
class Node;
class Ipv4EndPointDemux;
class Ipv4EndPoint;
class Ipv6EndPointDemux;
class Ipv6EndPoint;
class NetDevice;


class OspfL4Protocol : public IpL4Protocol {

  public:

    static const uint8_t PROTOCOL_NUMBER; // protocol number ( 0x59 or 89 decimal )

    OspfL4Protocol();
    ~OspfL4Protocol() override;

    // Delete copy constructor and assignment operator to avoid misuse
    OspfL4Protocol(const OspfL4Protocol&) = delete;
    OspfL4Protocol& operator=(const OspfL4Protocol&) = delete;

    /**
     * Set node associated with this stack
     * \param node the node
     */
    void SetNode(Ptr<Node> node);

    int GetProtocolNumber() const override;

    /**************************************************************************
     *
     * MRG: Inherited from IpL4Protocol
     *
     * You should look at the header file for this class but - I've copied this
     * documentation into this file.
     *
     * In our (LHU) implementation we are only going to support Ipv4 routing
     *
     *************************************************************************/

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId();

    /**
     * \brief Called from lower-level layers to send the packet up in the stack.
     * \param p packet to forward up
     * \param header IPv4 Header information
     * \param incomingInterface the Ipv4Interface on which the packet arrived
     * \returns Rx status code
     */
    IpL4Protocol::RxStatus Receive(Ptr<Packet> p,
                                   const Ipv4Header& header,
                                   Ptr<Ipv4Interface> interface) override;

    /**
     * \brief Called from lower-level layers to send the packet up in the stack.
     * \param p packet to forward up
     * \param header IPv6 Header information
     * \param incomingInterface the Ipv6Interface on which the packet arrived
     * \returns Rx status code
     */
    IpL4Protocol::RxStatus Receive(Ptr<Packet> p,
                                   const Ipv6Header& header,
                                   Ptr<Ipv6Interface> interface) override;

    /**
     * This method allows a caller to set the current down target callback
     * set for this L4 protocol (IPv4 case)
     *
     * \param cb current Callback for the L4 protocol
     */
    void SetDownTarget(IpL4Protocol::DownTargetCallback cb) override;

    /**
     * This method allows a caller to set the current down target callback
     * set for this L4 protocol (IPv6 case)
     *
     * \param cb current Callback for the L4 protocol
     */
    void SetDownTarget6(IpL4Protocol::DownTargetCallback6 cb) override;

    /**
     * This method allows a caller to get the current down target callback
     * set for this L4 protocol (IPv4 case)
     *
     * \return current Callback for the L4 protocol
     */
    IpL4Protocol::DownTargetCallback GetDownTarget() const override;

    /**
     * This method allows a caller to get the current down target callback
     * set for this L4 protocol (IPv6 case)
     *
     * \return current Callback for the L4 protocol
     */
    IpL4Protocol::DownTargetCallback6 GetDownTarget6() const override;

  protected:

    void DoDispose() override;

    /*
     * This function will notify other components connected to the node that a new stack member is
     * now connected This will be used to notify Layer 3 protocol of layer 4 protocol stack to
     * connect them together.
     */
    void NotifyNewAggregate() override;

  private:
    Ptr<Node> m_node;                    //!< The node this stack is associated with
    Ipv4EndPointDemux* m_endPoints;      //!< A list of IPv4 end points.
    Ipv6EndPointDemux* m_endPoints6;     //!< A list of IPv6 end points.

    IpL4Protocol::DownTargetCallback m_downTarget;   //!< Callback to send packets over IPv4
    IpL4Protocol::DownTargetCallback6 m_downTarget6; //!< Callback to send packets over IPv6

};

}

#endif // OSPF_L4_PROTOCOL_H