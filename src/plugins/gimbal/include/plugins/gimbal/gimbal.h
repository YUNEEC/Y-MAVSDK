// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/gimbal/gimbal.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "plugin_base.h"

namespace mavsdk {

class System;
class GimbalImpl;

/**
 * @brief Provide control over a gimbal.
 */
class Gimbal : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto gimbal = Gimbal(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Gimbal(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto gimbal = Gimbal(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Gimbal(std::shared_ptr<System> system); // new

    /**
     * @brief Destructor (internal use only).
     */
    ~Gimbal();

    /**
     * @brief Gimbal mode type.
     */
    enum class GimbalMode {
        YawFollow, /**< @brief Yaw follow will point the gimbal to the vehicle heading. */
        YawLock, /**< @brief Yaw lock will fix the gimbal poiting to an absolute direction. */
    };

    /**
     * @brief Stream operator to print information about a `Gimbal::GimbalMode`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::GimbalMode const& gimbal_mode);

    /**
     * @brief Control mode
     */
    enum class ControlMode {
        None, /**< @brief Indicates that the component does not have control over the gimbal. */
        Primary, /**< @brief To take primary control over the gimbal. */
        Secondary, /**< @brief To take secondary control over the gimbal. */
    };

    /**
     * @brief Stream operator to print information about a `Gimbal::ControlMode`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::ControlMode const& control_mode);

    /**
     * @brief Control status
     */
    struct ControlStatus {
        ControlMode control_mode{}; /**< @brief Control mode (none, primary or secondary) */
        int32_t sysid_primary_control{}; /**< @brief Sysid of the component that has primary control
                                            over the gimbal (0 if no one is in control) */
        int32_t compid_primary_control{}; /**< @brief Compid of the component that has primary
                                             control over the gimbal (0 if no one is in control) */
        int32_t sysid_secondary_control{}; /**< @brief Sysid of the component that has secondary
                                              control over the gimbal (0 if no one is in control) */
        int32_t
            compid_secondary_control{}; /**< @brief Compid of the component that has secondary
                                           control over the gimbal (0 if no one is in control) */
    };

    /**
     * @brief Equal operator to compare two `Gimbal::ControlStatus` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Gimbal::ControlStatus& lhs, const Gimbal::ControlStatus& rhs);

    /**
     * @brief Stream operator to print information about a `Gimbal::ControlStatus`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::ControlStatus const& control_status);

    /**
     * @brief Possible results returned for gimbal commands.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Command was accepted. */
        Error, /**< @brief Error occurred sending the command. */
        Timeout, /**< @brief Command timed out. */
        Unsupported, /**< @brief Functionality not supported. */
    };

    /**
     * @brief Stream operator to print information about a `Gimbal::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gimbal::Result const& result);

    /**
     * @brief Callback type for asynchronous Gimbal calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Set gimbal pitch and yaw angles.
     *
     * This sets the desired pitch and yaw angles of a gimbal.
     * Will return when the command is accepted, however, it might
     * take the gimbal longer to actually be set to the new angles.
     *
     * This function is non-blocking. See 'set_pitch_and_yaw' for the blocking counterpart.
     */
    void set_pitch_and_yaw_async(float pitch_deg, float yaw_deg, const ResultCallback callback);

    /**
     * @brief Set gimbal pitch and yaw angles.
     *
     * This sets the desired pitch and yaw angles of a gimbal.
     * Will return when the command is accepted, however, it might
     * take the gimbal longer to actually be set to the new angles.
     *
     * This function is blocking. See 'set_pitch_and_yaw_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result set_pitch_and_yaw(float pitch_deg, float yaw_deg) const;

    /**
     * @brief Set gimbal angular rates around pitch and yaw axes.
     *
     * This sets the desired angular rates around pitch and yaw axes of a gimbal.
     * Will return when the command is accepted, however, it might
     * take the gimbal longer to actually reach the angular rate.
     *
     * This function is non-blocking. See 'set_pitch_rate_and_yaw_rate' for the blocking
     * counterpart.
     */
    void set_pitch_rate_and_yaw_rate_async(
        float pitch_rate_deg_s, float yaw_rate_deg_s, const ResultCallback callback);

    /**
     * @brief Set gimbal angular rates around pitch and yaw axes.
     *
     * This sets the desired angular rates around pitch and yaw axes of a gimbal.
     * Will return when the command is accepted, however, it might
     * take the gimbal longer to actually reach the angular rate.
     *
     * This function is blocking. See 'set_pitch_rate_and_yaw_rate_async' for the non-blocking
     * counterpart.
     *
     * @return Result of request.
     */
    Result set_pitch_rate_and_yaw_rate(float pitch_rate_deg_s, float yaw_rate_deg_s) const;

    /**
     * @brief Set gimbal mode.
     *
     * This sets the desired yaw mode of a gimbal.
     * Will return when the command is accepted. However, it might
     * take the gimbal longer to actually be set to the new angles.
     *
     * This function is non-blocking. See 'set_mode' for the blocking counterpart.
     */
    void set_mode_async(GimbalMode gimbal_mode, const ResultCallback callback);

    /**
     * @brief Set gimbal mode.
     *
     * This sets the desired yaw mode of a gimbal.
     * Will return when the command is accepted. However, it might
     * take the gimbal longer to actually be set to the new angles.
     *
     * This function is blocking. See 'set_mode_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result set_mode(GimbalMode gimbal_mode) const;

    /**
     * @brief Set gimbal region of interest (ROI).
     *
     * This sets a region of interest that the gimbal will point to.
     * The gimbal will continue to point to the specified region until it
     * receives a new command.
     * The function will return when the command is accepted, however, it might
     * take the gimbal longer to actually rotate to the ROI.
     *
     * This function is non-blocking. See 'set_roi_location' for the blocking counterpart.
     */
    void set_roi_location_async(
        double latitude_deg, double longitude_deg, float altitude_m, const ResultCallback callback);

    /**
     * @brief Set gimbal region of interest (ROI).
     *
     * This sets a region of interest that the gimbal will point to.
     * The gimbal will continue to point to the specified region until it
     * receives a new command.
     * The function will return when the command is accepted, however, it might
     * take the gimbal longer to actually rotate to the ROI.
     *
     * This function is blocking. See 'set_roi_location_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result set_roi_location(double latitude_deg, double longitude_deg, float altitude_m) const;

    /**
     * @brief Take control.
     *
     * There can be only two components in control of a gimbal at any given time.
     * One with "primary" control, and one with "secondary" control. The way the
     * secondary control is implemented is not specified and hence depends on the
     * vehicle.
     *
     * Components are expected to be cooperative, which means that they can
     * override each other and should therefore do it carefully.
     *
     * This function is non-blocking. See 'take_control' for the blocking counterpart.
     */
    void take_control_async(ControlMode control_mode, const ResultCallback callback);

    /**
     * @brief Take control.
     *
     * There can be only two components in control of a gimbal at any given time.
     * One with "primary" control, and one with "secondary" control. The way the
     * secondary control is implemented is not specified and hence depends on the
     * vehicle.
     *
     * Components are expected to be cooperative, which means that they can
     * override each other and should therefore do it carefully.
     *
     * This function is blocking. See 'take_control_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result take_control(ControlMode control_mode) const;

    /**
     * @brief Release control.
     *
     * Release control, such that other components can control the gimbal.
     *
     * This function is non-blocking. See 'release_control' for the blocking counterpart.
     */
    void release_control_async(const ResultCallback callback);

    /**
     * @brief Release control.
     *
     * Release control, such that other components can control the gimbal.
     *
     * This function is blocking. See 'release_control_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result release_control() const;

    /**
     * @brief Callback type for subscribe_control.
     */

    using ControlCallback = std::function<void(ControlStatus)>;

    /**
     * @brief Subscribe to control status updates.
     *
     * This allows a component to know if it has primary, secondary or
     * no control over the gimbal. Also, it gives the system and component ids
     * of the other components in control (if any).
     */
    void subscribe_control(ControlCallback callback);

    /**
     * @brief Poll for 'ControlStatus' (blocking).
     *
     * @return One ControlStatus update.
     */
    ControlStatus control() const;

    /**
     * @brief Copy constructor.
     */
    Gimbal(const Gimbal& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Gimbal& operator=(const Gimbal&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<GimbalImpl> _impl;
};

} // namespace mavsdk