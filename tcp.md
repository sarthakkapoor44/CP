# TCP connection is:
    - connection oriented
    - full duplex
    - reliable inorder byte stream
    - point to point (multicasting is not possible with TCP)
    - pipelining
    - flow controlled
    - pipelining

Three way handshake :  client process sends a special TCP seg. , server process sends a special TCP seg. and then the client also sends a special seg. the first two donot not contain a payload but third can include an application data payload. this is a.k.a handshaking.

The max amount of application data that can be put in the TCP segement is dictated by the MSS( max segment size), as the segment goes to the network layer it becomes an IP datagram, taking 40 bytes of header info, so we determine the MSS by the phsyical link layer cap (Max transmission unit) - 40 bytes for the data that can be transferred. Each side has a TCP send buffer and the recieve buffer.It depends on the tcp when/how much to send segment from the send buffer to the network layer. To be precise MSS is the max size of the application data that can be send.

# TCP headers: 
1. sequence number
2. acknowledgement number
3. checksum
4. source port num
5. dest port num
6. recieve window
7. header length
8. flag fields -  ACK,SYN,RST,PSH,URG,FIN,CWR,ECE

