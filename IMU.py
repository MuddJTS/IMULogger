

class IMU():
	def __init__(self, i2c_address=0x00):
		self.i2c_address = i2c_address

	def init(self):
		pass

	def read_IMU(self):
		return -1.0