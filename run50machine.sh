#!/bin/bash

# for 循环：上面的 while 语句等价
for i in {1..50}; do
	./TcpClient &
	sleep 1
done
