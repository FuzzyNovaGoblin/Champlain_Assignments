#!/bin/bash
cd /home/fuzzy/DevSSD/champlain/CSI-230/cron-lab/
rsync -e "ssh -i keys/pull-log" -av pull-log@ec2-3-93-152-177.compute-1.amazonaws.com: apache-logs
logger -t $0 "apache logs pulled from pull-log@ec2-3-93-152-177.compute-1.amazonaws.com"
