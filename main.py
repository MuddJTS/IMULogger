
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

	tick = 0
	while True:
		tick += 1
		p = pressure.read_pressure()
		i = imu.read_IMU()
		data = "soemthing"
		#telemetry.send_data(data)

		# update all sensors
		pressure.update(logger, tick)
		imu.update(logger, tick)

		# log and send data
		telemetry.update(logger, tick)

if __name__ == "__main__":
	main()