import logging

class Logger():
	def __init__(self, name):
		# initialize logger object as self.log
		self.log = logging.getLogger(name)
		self.log.setLevel(logging.DEBUG)

		# create StreamHandler
		sh = logging.StreamHandler() 
		sh.setLevel(logging.DEBUG)

		# create FileHandler
		fh = logging.FileHandler("example.log") # create FileHandler that writes to example.log

		# set formatter
		formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
		sh.setFormatter(formatter)
		fh.setFormatter(formatter)

		# add handlers to self.log
		self.log.addHandler(sh)
		self.log.addHandler(fh)

	def debug(self):
		self.log.debug('This message should go to the log file')

	def info(self):
		self.log.info('So should this')

	def warning(self):
		self.log.warning('And this, too')

	def error(self):
		self.log.error('And non-ASCII stuff, too, like Øresund and Malmö')

	def send_to_telemetry(self):
		pass

if __name__ == "__main__":
	# test
	log = Logger("log")
	log.debug()