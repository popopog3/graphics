#include "Camera.h"
#include <glm/ext.hpp>

const glm::vec3 Camera::center_position() const
{
  return  glm::vec3(position_.x + front_dir_.x,
                 position_.y + front_dir_.y, 
                 position_.z + front_dir_.z);
}

// TODO: fill up the following functions properly 
void Camera::move_forward(float delta)
{	
	position_ = position_ + delta*front_dir_;
}

void Camera::move_backward(float delta)
{	
	position_ = position_ - delta*front_dir_;
}

void Camera::move_left(float delta)
{	
	position_ = position_ - delta*right_dir_;
}

void Camera::move_right(float delta)
{
	position_ = position_ + delta*right_dir_;
}

void Camera::rotate_left(float delta)
{
	glm::mat4 rmat = glm::rotate(delta, glm::vec3(0, 1, 0));	// È¸ÀüÇà·ÄÀ» ¸¸µë
	glm::vec4 new_front = rmat * glm::vec4(front_dir_, 1);		// °Â¸¦ °öÇØ
	front_dir_ = glm::vec3(new_front);
	glm::vec4 new_right = rmat * glm::vec4(right_dir_, 1);
	right_dir_ = glm::vec3(new_right);
}

void Camera::rotate_right(float delta)
{
	rotate_left(-delta);
}