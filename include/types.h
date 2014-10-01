#pragma once

struct MyMap{
  int size_x, size_y, min_x, min_y, max_x, max_y;
  int resolution, global_mapsize_x, global_mapsize_y, offset_x, offset_y;
  float prob[800][800];
};

struct LaserData{
  // Robot pose
  float x, y, theta;
  // Laser Pose (approximately 25 cm offset forward from true center of robot)
  float xl, yl, thetal;
  // Range readings of laser in cm. 180 readings span 180 degrees 
  // starting right, going left
  int r[180];
  // Timestamp of laser reading
  float ts;
};

struct OdometryData{
  // Coordinates of robot in standard odometry frame
  float x, y, theta;
  // Timestamp of odometry reading
  float ts;
};


struct Coord{
  int row, col;
};


class Particle {
public:
  Particle(int x_val, int y_val, float theta_val) :
    x(x_val),
    y(y_val),
    theta(theta_val) {};

  float getX() {return this->x;}

  float getY() {return this->y;}

  float getTheta() {return this->theta;}

  void setX(int x_in) {this->x = x_in; return;}

  void setY(int y_in) {this->y = y_in; return;}

  void setTheta(double theta_in) {this->theta = theta_in; return;}

private:
  int x, y;
  float theta;
};

