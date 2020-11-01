#!/bin/bash
cd /home/fuzzy/DevSSD/champlain/CSI-230/cron-lab/
rsync -e "ssh -i keys/push-web" -vraO --no-perms --delete --chmod=660 --chown=push-web:www-data web-content/ push-web@ec2-3-93-152-177.compute-1.amazonaws.com:
