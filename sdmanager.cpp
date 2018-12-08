
SdFatSdio sd;

if (!sd.begin()) {
  sd.initErrorHalt("SdFatSdio begin() failed");
}
sd.chvol();

File file;
if (!file.open("TeensyDemo.bin", O_RDWR | O_CREAT)) {
	errorHalt("open failed");
}
