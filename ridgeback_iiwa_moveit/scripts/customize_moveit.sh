#!/usr/bin/env bash
if [ $# == 1 ]
then
  echo "Creating Directory <" $PWD"/"$1 ">"
  mkdir "$1"
  cd "$1"

  echo "Copying IIWA Moveit Config"
  cp -r $(catkin_find ridgeback_iiwa_moveit)/. .
  echo "Updating Package"
  grep -rli 'ridgeback_iiwa_moveit' * | xargs -i@ sed -i 's/ridgeback_iiwa_moveit/'$1'/g' @
  echo "Done"

else
  echo "USAGE: customize_moveit.sh [new_moveit_package_name]"
fi
