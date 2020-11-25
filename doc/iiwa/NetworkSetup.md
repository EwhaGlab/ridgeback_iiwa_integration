# Network Setup for IIWA

If you have trouble understanding the documentation below, please refer to this [wiki](https://github.com/IFL-CAMP/iiwa_stack/wiki#setup-guide) as supplementary materials.

## Working with IIWA alone

We are setting up your **PC** as a **ROS_MASTER**.

1. Make sure the ethernet cable is connected to **X66 port** of SUNRISE Cabinet. 

2. **(Wired)** Connect network cable to your PC or **(Wireless)** Connect your PC wifi to **COM_GR_5G**.   
   Manually setup the network as below:

	|  Address           | Netmask         | Gateway         |
	|  :---------------: | :-------------: | :-------------: |
	|  172.31.1.2        |  255.255.255.0  |  192.168.168.0  |

   Use ```ifconfig``` to check whether network is well setup.
   
3. Add following lines to **~/.bashrc**:  
  ```sh
   export ROS_IP=172.31.1.2  
   export ROS_MASTER_URI=http://$ROS_IP:11311
  ```

## Working with IIWA ridgeback

We are setting up **Ridgeback** as a **ROS_MASTER**.

1. Make sure the ethernet cable is connected to **X66 port** of SUNRISE Cabinet. 

2. **(Wireless)** Connect your PC wifi to **COM_GR_5G**.   
   Manually setup the network as below:

	|  Address           | Netmask         | Gateway         |
	|  :---------------: | :-------------: | :-------------: |
	|  172.31.1.*50*        |  255.255.255.0  |  192.168.168.0  |

   ⚠️ Make sure the address is not overlapped with your coworkers. Change 50 to anything else but 147 (KUKA cabinet).
   
   
   Use ```ifconfig``` to check whether network is well setup.
   
3. Add following to **~/.bashrc**:   
   ```sh
   export ROS_IP=172.31.1.50 
   export ROS_MASTER_URI=http://172.31.1.2:11311
   ```
   
    ⚠️ Make sure that you put the correct IP address that you setup in 2.
