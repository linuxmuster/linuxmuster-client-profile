#!/bin/bash

cp debian/changelog debian/changelog.trusty
sed -i "s/trusty/precise/g" debian/changelog
dpkg-buildpackage
mv debian/changelog.trusty debian/changelog

