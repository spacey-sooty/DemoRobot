#include "intake.h"

intake::intake(intakeConfig config, frc::XboxController &driver) : _config(config), _driver(driver) {}

void intake::OnStart() {
  std::cout << "Starting" << std::endl;
}

void intake::OnUpdate(units::second_t dt) {
  switch (_state)
  {
  case intakeState::kIdle :
    break;

  case intakeState::kHolding :
    GetConfig().left.controller.Set(ControlMode::PercentOutput, -0.05);
    GetConfig().right.controller.Set(ControlMode::PercentOutput, -0.05);
    break;
  case intakeState::kIntaking :
    GetConfig().left.controller.Set(ControlMode::PercentOutput, -0.95);
    GetConfig().right.controller.Set(ControlMode::PercentOutput, -0.95);
    break;
  }
}