Debug the first test1 with:

```
make test1 && pr -w $COLUMNS -m -t du1-test1.out ../public-tests/du1-test1.out && cat ../public-tests/du1-test1.mls
```

Useful file for `make_*` is `dummyg.hpp`, also contains definitions. 