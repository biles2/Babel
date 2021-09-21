#include <Networking/RawPacket.hpp>
#include <Networking/Packets/PacketCmdRegister.hpp>
#include <memory>

Babel::Networking::RawPacket::RawPacket(std::vector<char> data) : _data(data) {
}

Babel::Networking::RawPacket::RawPacket(const Babel::Networking::RawPacket &other) : _data(other._data) {
}

Babel::Networking::RawPacket &Babel::Networking::RawPacket::operator=(const Babel::Networking::RawPacket &other) {
    _data = other._data;
    return *this;
}

std::shared_ptr<Babel::Networking::Packet> Babel::Networking::RawPacket::deserialize() {
    if (getPacketType() == PacketUnknown)
        return std::make_shared<Babel::Networking::Packet>(PacketUnknown);

    switch (getPacketType()) {
        case PacketCmdRegister: return std::make_shared<Packets::PacketCmdRegister>(_data);
        default: return std::make_shared<Babel::Networking::Packet>(PacketUnknown);
    }
}

Babel::Networking::PacketType Babel::Networking::RawPacket::getPacketType() const {
    if (_data.size() < sizeof(int) + sizeof(char))
        return PacketUnknown;
    return static_cast<PacketType>(_data[4]);
}

const std::vector<char> Babel::Networking::RawPacket::getData() const {
    return _data;
}
