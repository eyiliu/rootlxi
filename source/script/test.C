

{
  std::stringstream ss_loadlib;
  std::string wkfd = gSystem->WorkingDirectory();
  ss_loadlib <<wkfd.c_str()<<"/../../INSTALL/lib/"<<"librootlxi.so";

  std::cout<<"loading external rootlib: "<<ss_loadlib.str()<<std::endl;
  gSystem->Load(ss_loadlib.str().c_str());

  char response[65536];
  int device, length, timeout = 2000;

  std::string command("*IDN?");

  // Initialize LXI library
  lxi_init();

  // Connect to LXI device
  device = lxi_connect("192.168.21.54", 0, "inst0", timeout, VXI11);

  // Send SCPI command
  lxi_send(device, command.c_str(), command.size(), timeout);

  // Wait for response
  lxi_receive(device, response, sizeof(response), timeout);

  printf("LXI Response:\n%s\n\n", response);


  // Disconnect
  lxi_disconnect(device);
}
