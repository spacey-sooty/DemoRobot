#include <db.h>

db::db(dbConfig config, frc::XboxController &driver) : _config(config), _driver(driver) {} 

void db::OnStart() { 
  std::cout << "Starting" << std::endl; 
} 

void db::OnUpdate(units::second_t dt) { 
  switch(_state) { 
    case dbState::kIdle : 
      break; 
 
    case dbState::kRaw : 
      double y = (_driver.GetLeftY() > 0.15) ? _driver.GetLeftY() : 0; 
      GetConfig().left1.controller.Set(ControlMode::PercentOutput, y); 
      GetConfig().left2.controller.Set(ControlMode::PercentOutput, y); 
      GetConfig().left3.controller.Set(ControlMode::PercentOutput, y); 
      GetConfig().right1.controller.Set(ControlMode::PercentOutput, y); 
      GetConfig().right2.controller.Set(ControlMode::PercentOutput, y); 
      GetConfig().right3.controller.Set(ControlMode::PercentOutput, y); 

      double spin = (_driver.GetRightX() > 0.15) ? _driver.GetRightX() : 0;
      GetConfig().left1.controller.Set(ControlMode::PercentOutput,  spin);
      GetConfig().left2.controller.Set(ControlMode::PercentOutput,  spin);
      GetConfig().left3.controller.Set(ControlMode::PercentOutput,  spin);
      GetConfig().right1.controller.Set(ControlMode::PercentOutput, -spin);
      GetConfig().right2.controller.Set(ControlMode::PercentOutput, -spin);
      GetConfig().right3.controller.Set(ControlMode::PercentOutput, -spin);
      break; 
  } 
} 