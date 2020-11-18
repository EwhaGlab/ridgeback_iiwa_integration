# Network Setup for IIWA

If you have trouble understanding the documentation below, please refer to this [wiki](https://github.com/IFL-CAMP/iiwa_stack/wiki#setup-guide) as supplementary materials.



1. Make sure the ethernet cable is connected to **X66 port** of SUNRISE Cabinet. 

2. **(Wired)** Connect network cable to your PC or **(Wireless)** Connect your PC wifi to **COM_GR_KONI**.   
   Below are numbers for IPv4 manual:

	|  Address           | Netmask         | Gateway         |
	|  :---------------: | :-------------: | :-------------: |
	|  172.31.1.150      |  255.255.255.0  |  192.168.168.0  |

   Use ```ifconfig``` to check whether network is well setup.
   
3. Add following to **~/.bashrc**:   
	```
   export ROS_IP=172.31.1.150  
   export ROS_MASTER_URI=http://$ROS_IP:11311
