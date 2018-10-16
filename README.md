# Exercism CPP track

After having a rough time getting my environment set up to run the tests (installing a correct version of boost specifically) I decided to stop messing up my machine in the process. I'm still learning Docker, so this was a great exercise in and of itself to get a build and test environment set up in a Docker image.

The primary intent of this repo is to record my learning of c++ using exercism.io. First goal is to give a valid solution, however I want to go about it or however feel natural to me. Then, to give a solution that is considered best practices in c++. Any optimizations I find to my own solutions or other interesting ways I want to try to solve them are fine after this point, it's the journey not the destination that matters here.

# Exercism CPP Build and Test Environment Configuration

See Docker-setup directory to modify base image. By having the base image already built, it doens't have to be rebuilt each time you run the tests.

Be sure to update the "DIR" arg on line 5 of the Dockerfile to be the same as the example name. In the Hello World example, it is `hello-world`.

```
docker build --rm -f "Dockerfile" -t exercism-cpp-hello-world:test-1 .
```

Output should display if the tests were successful or not.
```
Running 1 test case...

*** No errors detected
[100%] Built target hello-world
```
or
```
Running 1 test case...
/usr/src/hello-world/hello_world_test.cpp(7): fatal error: in "test_hello": critical check "Hello, World!" == hello_world::hello() has failed [Hello, World! != no]

*** 1 failure is detected in the test module "Master Test Suite"
CMakeFiles/hello-world.dir/build.make:123: recipe for target 'hello-world' failed
make[2]: *** [hello-world] Error 201
make[2]: *** Deleting file 'hello-world'
CMakeFiles/Makefile2:67: recipe for target 'CMakeFiles/hello-world.dir/all' failed
make[1]: *** [CMakeFiles/hello-world.dir/all] Error 2
Makefile:83: recipe for target 'all' failed
make: *** [all] Error 2
```

# Docker Cleanup
Run this to remove all images with a `test` tag
```
docker rmi $(docker images --format '{{.Repository}}:{{.Tag}}' | grep ':test')
```