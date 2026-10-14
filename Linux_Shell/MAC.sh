#!/bin/sh

# TASK
#• Write a command line that displays your machine’s MAC addresses. Each address
#must be followed by a line break.

ifconfig | grep ether | awk '{print $2}'
