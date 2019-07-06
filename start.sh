#!/bin/bash

i=1
while [ $i -le 20 ];do
	/home/itt/Coding/QtCoding/sendData/TcpClient $i &
	i=$(expr $i + 1)
done
