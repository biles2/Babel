cmake_minimum_required(VERSION 3.10)
project(Babel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup(TARGETS)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(babel_client client/main.cpp
        shared/Networking/RawPacket.cpp shared/Networking/RawPacket.hpp
        shared/Networking/Packet.cpp shared/Networking/Packet.hpp
        shared/Networking/RawTypes.hpp
        shared/Networking/ArgumentsWriter.cpp shared/Networking/ArgumentsWriter.hpp
        shared/Networking/ArgumentsReader.cpp shared/Networking/ArgumentsReader.hpp
        shared/Networking/Packets/PacketCmdRegister.cpp shared/Networking/Packets/PacketCmdRegister.hpp
        shared/Networking/Packets/PacketRespRegister.cpp shared/Networking/Packets/PacketRespRegister.hpp
        shared/Networking/Packets/PacketCmdLogin.cpp shared/Networking/Packets/PacketCmdLogin.hpp
        shared/Networking/Packets/PacketRespLogin.cpp shared/Networking/Packets/PacketRespLogin.hpp
        shared/Networking/Packets/PacketCmdLogout.cpp shared/Networking/Packets/PacketCmdLogout.hpp
        client/Ui/ConnectionWindow/ConnectionWindow.cpp client/Ui/ConnectionWindow/ConnectionWindow.hpp
        client/Ui/ConnectionWindow/ConnectionPage.cpp client/Ui/ConnectionWindow/ConnectionPage.hpp
        client/Ui/FriendsWindow.cpp client/Ui/FriendsWindow.hpp
        client/Ui/AddFriendPage.cpp client/Ui/AddFriendPage.hpp
        client/Ui/FriendInvitesPage.cpp client/Ui/FriendInvitesPage.hpp
        client/Ui/FriendInviteWidget.cpp client/Ui/FriendInviteWidget.hpp
        client/Ui/MainWindow.cpp client/Ui/MainWindow.hpp
        client/Ui/ChatWidget.cpp client/Ui/ChatWidget.hpp
        client/Ui/FriendItemWidget.cpp client/Ui/FriendItemWidget.hpp
        client/Ui/MessageWidget.cpp client/Ui/MessageWidget.hpp
        client/Ui/CallWindow.cpp client/Ui/CallWindow.hpp
        client/Networking/Client.cpp client/Networking/Client.hpp 
        client/Audio/Portaudio.cpp client/Audio/Portaudio.hpp
        client/Audio/Opus.cpp client/Audio/Opus.hpp
        client/LibHandler/LibHandler.cpp client/LibHandler/LibHandler.hpp
        client/Audio/IAudio.hpp
        client/Networking/ClientUdp.cpp client/Networking/ClientUdp.hpp
        client/Networking/IClient.hpp
        client/Audio/ICompressor.h
        shared/Networking/Packets/PacketAudio.cpp shared/Networking/Packets/PacketAudio.hpp
        shared/Networking/Packets/PacketCmdInviteFriend.cpp shared/Networking/Packets/PacketCmdInviteFriend.hpp
        shared/Networking/Packets/PacketRespInviteFriend.cpp shared/Networking/Packets/PacketRespInviteFriend.hpp
        shared/Networking/Packets/PacketCmdAcceptFriend.cpp shared/Networking/Packets/PacketCmdAcceptFriend.hpp
        shared/Networking/Packets/PacketRespAcceptFriend.cpp shared/Networking/Packets/PacketRespAcceptFriend.hpp
        shared/Networking/Packets/PacketCmdDenyFriend.cpp shared/Networking/Packets/PacketCmdDenyFriend.hpp
        shared/Networking/Packets/PacketRespDenyFriend.cpp shared/Networking/Packets/PacketRespDenyFriend.hpp
        shared/Networking/Packets/PacketRespDenyFriend.cpp shared/Networking/Packets/PacketRespDenyFriend.hpp
        shared/Networking/Packets/PacketInviteReceived.cpp shared/Networking/Packets/PacketInviteReceived.hpp
        shared/Networking/Packets/PacketFriendAdded.cpp shared/Networking/Packets/PacketFriendAdded.hpp
        shared/Networking/Packets/PacketFriendDenied.cpp shared/Networking/Packets/PacketFriendDenied.hpp
        shared/Networking/Packets/PacketCmdListFriends.cpp shared/Networking/Packets/PacketCmdListFriends.hpp
        shared/Networking/Packets/PacketRespListFriends.cpp shared/Networking/Packets/PacketRespListFriends.hpp
        shared/Networking/PacketTypes.hpp
        shared/Networking/Packets/PacketCmdListInvites.cpp shared/Networking/Packets/PacketCmdListInvites.hpp
        shared/Networking/Packets/PacketRespListInvites.cpp shared/Networking/Packets/PacketRespListInvites.hpp
        shared/Networking/Packets/PacketCall.cpp shared/Networking/Packets/PacketCall.hpp
        shared/Networking/Packets/PacketCallReceived.cpp shared/Networking/Packets/PacketCallReceived.hpp
        shared/Networking/Packets/PacketAcceptCall.cpp shared/Networking/Packets/PacketAcceptCall.hpp
        shared/Networking/Packets/PacketStartVoip.cpp shared/Networking/Packets/PacketStartVoip.hpp
        shared/Networking/Packets/PacketCmdListMessages.cpp shared/Networking/Packets/PacketCmdListMessages.hpp
        shared/Networking/Packets/PacketRespListMessages.cpp shared/Networking/Packets/PacketRespListMessages.hpp
        shared/Networking/Packets/PacketMessageOpen.cpp shared/Networking/Packets/PacketMessageOpen.hpp
        shared/Networking/Packets/PacketMessageReceive.cpp shared/Networking/Packets/PacketMessageReceive.hpp
        shared/Networking/Packets/PacketMessageSend.cpp shared/Networking/Packets/PacketMessageSend.hpp)
target_include_directories(babel_client PUBLIC ${CONAN_INCLUDE_DIRS})
target_include_directories(babel_client PUBLIC ${CMAKE_SOURCE_DIR}/shared)
target_include_directories(babel_client PUBLIC ${CMAKE_SOURCE_DIR}/client)
target_link_directories(babel_client PUBLIC ${CMAKE_BINARY_DIR}/bin/lib)
target_link_libraries(babel_client CONAN_PKG::portaudio CONAN_PKG::opus Qt5::Widgets Qt5::Network)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/client/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_executable(babel_server server/main.cpp
        shared/Networking/RawPacket.cpp shared/Networking/RawPacket.hpp
        shared/Networking/Packet.cpp shared/Networking/Packet.hpp
        shared/Networking/RawTypes.hpp
        shared/Networking/ArgumentsReader.cpp shared/Networking/ArgumentsReader.hpp
        shared/Networking/ArgumentsWriter.cpp shared/Networking/ArgumentsWriter.hpp
        shared/Networking/Packets/PacketCmdRegister.cpp shared/Networking/Packets/PacketCmdRegister.hpp
        shared/Networking/Packets/PacketRespRegister.cpp shared/Networking/Packets/PacketRespRegister.hpp
        shared/Networking/Packets/PacketCmdLogin.cpp shared/Networking/Packets/PacketCmdLogin.hpp
        shared/Networking/Packets/PacketRespLogin.cpp shared/Networking/Packets/PacketRespLogin.hpp
        shared/Networking/Packets/PacketCmdLogout.cpp shared/Networking/Packets/PacketCmdLogout.hpp
        server/Database/Database.cpp server/Database/Database.hpp
        server/Database/IModel.hpp
        server/Database/User.cpp server/Database/User.hpp
        server/Networking/Server.cpp server/Networking/Server.hpp
        server/Networking/Session.cpp server/Networking/Session.hpp
        server/Database/Friendship.cpp server/Database/Friendship.hpp
        shared/Networking/Packets/PacketCmdInviteFriend.cpp shared/Networking/Packets/PacketCmdInviteFriend.hpp
        shared/Networking/Packets/PacketRespInviteFriend.cpp shared/Networking/Packets/PacketRespInviteFriend.hpp
        shared/Networking/Packets/PacketCmdAcceptFriend.cpp shared/Networking/Packets/PacketCmdAcceptFriend.hpp
        shared/Networking/Packets/PacketRespAcceptFriend.cpp shared/Networking/Packets/PacketRespAcceptFriend.hpp
        shared/Networking/Packets/PacketCmdDenyFriend.cpp shared/Networking/Packets/PacketCmdDenyFriend.hpp
        shared/Networking/Packets/PacketRespDenyFriend.cpp shared/Networking/Packets/PacketRespDenyFriend.hpp
        shared/Networking/Packets/PacketInviteReceived.cpp shared/Networking/Packets/PacketInviteReceived.hpp
        shared/Networking/Packets/PacketFriendAdded.cpp shared/Networking/Packets/PacketFriendAdded.hpp
        shared/Networking/Packets/PacketFriendDenied.cpp shared/Networking/Packets/PacketFriendDenied.hpp
        shared/Networking/Packets/PacketCmdListFriends.cpp shared/Networking/Packets/PacketCmdListFriends.hpp
        shared/Networking/Packets/PacketRespListFriends.cpp shared/Networking/Packets/PacketRespListFriends.hpp
        shared/Networking/PacketTypes.hpp
        shared/Networking/Packets/PacketCmdListInvites.cpp shared/Networking/Packets/PacketCmdListInvites.hpp
        shared/Networking/Packets/PacketRespListInvites.cpp shared/Networking/Packets/PacketRespListInvites.hpp
        server/Networking/HandlePacket.cpp server/Networking/HandlePacket.hpp
        server/Networking/IHandlePacket.hpp
        shared/Networking/Packets/PacketAudio.cpp shared/Networking/Packets/PacketAudio.hpp
        shared/Networking/Packets/PacketCall.cpp shared/Networking/Packets/PacketCall.hpp
        server/Networking/Call.cpp server/Networking/Call.hpp
        shared/Networking/Packets/PacketCallReceived.cpp shared/Networking/Packets/PacketCallReceived.hpp
        shared/Networking/Packets/PacketAcceptCall.cpp shared/Networking/Packets/PacketAcceptCall.hpp
        shared/Networking/Packets/PacketStartVoip.cpp shared/Networking/Packets/PacketStartVoip.hpp
        server/Database/Message.cpp server/Database/Message.hpp
        shared/Networking/Packets/PacketRespListMessages.cpp shared/Networking/Packets/PacketRespListMessages.hpp
        shared/Networking/Packets/PacketMessageSend.cpp shared/Networking/Packets/PacketMessageSend.hpp)
target_include_directories(babel_server PUBLIC ${CONAN_INCLUDE_DIRS})
target_include_directories(babel_server PUBLIC ${CMAKE_SOURCE_DIR}/shared)
target_include_directories(babel_server PUBLIC ${CMAKE_SOURCE_DIR}/server)
target_link_directories(babel_server PUBLIC ${CMAKE_BINARY_DIR}/bin/lib)
target_link_libraries(babel_server CONAN_PKG::asio CONAN_PKG::sqlite3)