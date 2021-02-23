// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see
// https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/tracking_server/tracking_server.proto)

#include <iomanip>

#include "tracking_server_impl.h"
#include "plugins/tracking_server/tracking_server.h"

namespace mavsdk {

using TrackPoint = TrackingServer::TrackPoint;
using TrackRectangle = TrackingServer::TrackRectangle;

TrackingServer::TrackingServer(System& system) : PluginBase(), _impl{new TrackingServerImpl(system)}
{}

TrackingServer::TrackingServer(std::shared_ptr<System> system) :
    PluginBase(),
    _impl{new TrackingServerImpl(system)}
{}

TrackingServer::~TrackingServer() {}

void TrackingServer::set_tracking_point_status(TrackPoint tracked_point) const
{
    _impl->set_tracking_point_status(tracked_point);
}

void TrackingServer::set_tracking_rectangle_status(TrackRectangle tracked_rectangle) const
{
    _impl->set_tracking_rectangle_status(tracked_rectangle);
}

void TrackingServer::set_tracking_off_status() const
{
    _impl->set_tracking_off_status();
}

void TrackingServer::subscribe_tracking_point_command(TrackingPointCommandCallback callback)
{
    _impl->subscribe_tracking_point_command(callback);
}

void TrackingServer::subscribe_tracking_rectangle_command(TrackingRectangleCommandCallback callback)
{
    _impl->subscribe_tracking_rectangle_command(callback);
}

void TrackingServer::subscribe_tracking_off_command(TrackingOffCommandCallback callback)
{
    _impl->subscribe_tracking_off_command(callback);
}

TrackingServer::Result
TrackingServer::respond_tracking_point_command(CommandAnswer command_answer) const
{
    return _impl->respond_tracking_point_command(command_answer);
}

TrackingServer::Result
TrackingServer::respond_tracking_rectangle_command(CommandAnswer command_answer) const
{
    return _impl->respond_tracking_rectangle_command(command_answer);
}

TrackingServer::Result
TrackingServer::respond_tracking_off_command(CommandAnswer command_answer) const
{
    return _impl->respond_tracking_off_command(command_answer);
}

bool operator==(const TrackingServer::TrackPoint& lhs, const TrackingServer::TrackPoint& rhs)
{
    return ((std::isnan(rhs.point_x) && std::isnan(lhs.point_x)) || rhs.point_x == lhs.point_x) &&
           ((std::isnan(rhs.point_y) && std::isnan(lhs.point_y)) || rhs.point_y == lhs.point_y) &&
           ((std::isnan(rhs.radius) && std::isnan(lhs.radius)) || rhs.radius == lhs.radius);
}

std::ostream& operator<<(std::ostream& str, TrackingServer::TrackPoint const& track_point)
{
    str << std::setprecision(15);
    str << "track_point:" << '\n' << "{\n";
    str << "    point_x: " << track_point.point_x << '\n';
    str << "    point_y: " << track_point.point_y << '\n';
    str << "    radius: " << track_point.radius << '\n';
    str << '}';
    return str;
}

bool operator==(
    const TrackingServer::TrackRectangle& lhs, const TrackingServer::TrackRectangle& rhs)
{
    return ((std::isnan(rhs.top_left_corner_x) && std::isnan(lhs.top_left_corner_x)) ||
            rhs.top_left_corner_x == lhs.top_left_corner_x) &&
           ((std::isnan(rhs.top_left_corner_y) && std::isnan(lhs.top_left_corner_y)) ||
            rhs.top_left_corner_y == lhs.top_left_corner_y) &&
           ((std::isnan(rhs.bottom_right_corner_x) && std::isnan(lhs.bottom_right_corner_x)) ||
            rhs.bottom_right_corner_x == lhs.bottom_right_corner_x) &&
           ((std::isnan(rhs.bottom_right_corner_y) && std::isnan(lhs.bottom_right_corner_y)) ||
            rhs.bottom_right_corner_y == lhs.bottom_right_corner_y);
}

std::ostream& operator<<(std::ostream& str, TrackingServer::TrackRectangle const& track_rectangle)
{
    str << std::setprecision(15);
    str << "track_rectangle:" << '\n' << "{\n";
    str << "    top_left_corner_x: " << track_rectangle.top_left_corner_x << '\n';
    str << "    top_left_corner_y: " << track_rectangle.top_left_corner_y << '\n';
    str << "    bottom_right_corner_x: " << track_rectangle.bottom_right_corner_x << '\n';
    str << "    bottom_right_corner_y: " << track_rectangle.bottom_right_corner_y << '\n';
    str << '}';
    return str;
}

std::ostream& operator<<(std::ostream& str, TrackingServer::Result const& result)
{
    switch (result) {
        case TrackingServer::Result::Unknown:
            return str << "Unknown";
        case TrackingServer::Result::Success:
            return str << "Success";
        case TrackingServer::Result::NoSystem:
            return str << "No System";
        case TrackingServer::Result::ConnectionError:
            return str << "Connection Error";
        default:
            return str << "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, TrackingServer::CommandAnswer const& command_answer)
{
    switch (command_answer) {
        case TrackingServer::CommandAnswer::Accepted:
            return str << "Accepted";
        case TrackingServer::CommandAnswer::TemporarilyRejected:
            return str << "Temporarily Rejected";
        case TrackingServer::CommandAnswer::Denied:
            return str << "Denied";
        case TrackingServer::CommandAnswer::Unsupported:
            return str << "Unsupported";
        case TrackingServer::CommandAnswer::Failed:
            return str << "Failed";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk