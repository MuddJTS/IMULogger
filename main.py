
from PressureSensor import PressureSensor
from IMU import IMU
from Telemetry import Telemetry
from Logger import Logger

def main():
	pressure = PressureSensor()
	imu = IMU()
	telemetry = Telemetry()
	logger = Logger()

	pressure.init()
	imu.init()
	telemetry.init()

	while True:
		p = pressure.read_pressure()
		i = imu.read_IMU()
		data = "soemthing"
		#telemetry.send_data(data)

		# update all sensors
		pressure.update(logger)
		imu.update(logger)

		# log and send data
		telemetry.update(logger)

if __name__ == "__main__":
	main()