

class PressureSensor():
	def __init__(self, i2c_address=0x00):
		self.i2c_address = i2c_address

	def init(self):
		pass

	def read_pressure(self):
		return -1.0

if __name__ == "__main__":
	print('hello')