#include <iostream>

using namespace std;

#include <MinimalSocket/udp/UdpSocket.h>

int main()
{

    MinimalSocket::Port this_socket_port = 15768;
    MinimalSocket::udp::Udp<true> udp_socket(this_socket_port, MinimalSocket::AddressFamily::IP_V6);

    bool success = udp_socket.open();

    // send a message to another udp
    MinimalSocket::Address other_recipient_udp = MinimalSocket::Address{"192.168.125.85", 15768};
    udp_socket.sendTo("a message to send", other_recipient_udp);
    // receive a message from another udp reaching this one
    std::size_t message_max_size = 1000;
    auto received_message = udp_socket.receive(message_max_size);
    // check the sender address
    MinimalSocket::Address other_sender_udp = received_message->sender;
    // access the received message
    // resized to the nunber of bytes
    // actually received
    std::string received_message_content = received_message->received_message;

    cout << received_message_content << endl;
    return 0;
}
