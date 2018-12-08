
#ifndef __FILESTRUCTURES_H__
#define __FILESTRUCTURES_H__

struct BNOData {
	unsigned long time;

	imu::Quaternion quat;
	imu::Vector<3> acc;
	imu::Vector<3> gyr;
	imu::Vector<3> mag;
}
#endif