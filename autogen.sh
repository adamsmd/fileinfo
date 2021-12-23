#!/bin/bash

set -ex

autoscan
autoreconf --verbose --install --warnings=all
