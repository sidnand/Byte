#!/bin/bash

gcc tests/io/reader.test.c src/io/reader.c ./libs/unity/unity.c -o bins/tests/io/reader.test
./bins/tests/io/reader.test