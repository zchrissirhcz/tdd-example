# tdd-example

## Intro
Implement Arabic to Roman numerals converter, in a TDD(Test-Driven-Development) manner.

## Get source
```bash
cd ~/work
git clone https://github.com/zchrissirhcz/tdd-example
cd tdd-example
code-insiders .
```

## Usage
```bash
mkdir build
cd build
cmake ..
make

make test
make coverage

cd coverage_report
python -m http.server 7082
```

## Screenshots
![](coverage1.png)

![](coverage2.png)