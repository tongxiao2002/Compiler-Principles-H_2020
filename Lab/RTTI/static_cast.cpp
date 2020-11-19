#include <iostream>
#include <list>
#include <string>
#include <cassert>

#define VALUE 0
#define INSTRUCTION 1
#define UNARYINST 2
#define BINARYINST 3
#define BASICBLOCK 4

class Value {
public:
    Value() {
        setName("Value");
		setTag(VALUE);
    }
    virtual ~Value() {}
    void setName(std::string n) {
        name = n;
    }
    std::string getName() {
        return name;
    }
    virtual void print() {
        std::cout << "I'm a " << getName() << std::endl;
    }
	void setTag(int tag)	//根据 tag 区分子类
	{
		this->Tag = tag;
	}
	int getTag()
	{
		return this->Tag;
	}
protected:
	int Tag;
    std::string name;
};

class Instruction : public Value {
public:
    Instruction() {
        setName("Instruction");
		setTag(INSTRUCTION);
    }
    virtual void print() override {
        std::cout << getName() << std::endl;
    }
};

class UnaryInst : public Instruction {
public:
    UnaryInst() {
        setName("UnaryInst");
		setTag(UNARYINST);
    }
};

class BinaryInst : public Instruction {
public:
    BinaryInst() {
        setName("BinaryInst");
		setTag(BINARYINST);
    }
};

class BasicBlock : public Value {
public:
    BasicBlock() {
        setName("BasicBlock");
		setTag(BASICBLOCK);
    }
    ~BasicBlock() {
        for (auto v : values) {
            delete v;
        }
    }
    virtual void print() override {
        int unary_cnt = 0, binary_cnt = 0;
        for (auto v : values) {
            if (v->getTag() == UNARYINST) {
                unary_cnt++;
            }
            else if (v->getTag() == BINARYINST) {
                binary_cnt++;
            }
            else {
                std::cerr << "Unspported instruction: " << v->getName() << std::endl;
                abort();
            }
        }
        std::cout << name << ": " << unary_cnt << " unary instructions, " 
            << binary_cnt << " binary instructions" << std::endl;
        for (auto v : values) {
            std::cout << "  " << v->getName() << std::endl;
        }
    }
    void addValue(Value *v) {
        values.push_back(v);
    }
private:
    std::list<Value *> values;
};

int main()
{
    BasicBlock *bb = new BasicBlock();
    bb->addValue(new UnaryInst());
    bb->addValue(new UnaryInst());
    bb->addValue(new BinaryInst());
    bb->addValue(new UnaryInst());
    bb->addValue(new BinaryInst());
    bb->print();
    delete bb;
    return 0;
}