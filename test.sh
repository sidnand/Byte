#!/bin/bash

gcc tests/utils/reader.test.c src/utils/reader.c ./libs/unity/unity.c -o bins/tests/utils/reader.test
./bins/tests/utils/reader.test