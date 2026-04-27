#ifndef BLOCK1_KLEMAN_MANIPULATOR_HPP
#define BLOCK1_KLEMAN_MANIPULATOR_HPP

#include <array>
#include <vector>

namespace block1_kleman
{

    class Manipulator
    {
    public:
        using JointArray = std::array<double, 6>;

        struct TrajectoryPoint
        {
            double time;
            JointArray position;
            JointArray velocity;
            JointArray acceleration;
        };

        Manipulator() = default;

        std::vector<TrajectoryPoint> generatePTP(
          const JointArray & start,
          const JointArray & goal,
          double duration,
          double dt) const;

    private:
        double blendingPosition(double tau) const;
        double blendingVelocity(double tau, double duration) const;
        double blendingAcceleration(double tau, double duration) const;
    };

}  // namespace block1_kleman

#endif