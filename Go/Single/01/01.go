package mainR

import "fmt"

func MakeSlice(length, capactiy int) []int {
	return make([]int, length, capacity)
}

func PersonFromUser() {
}

func (p *Person) Init(name string, age int) {
	p.Name = name
	p.age = age
}

func (p *Person) IsAdult() bool {
	return p.Age >= 18
}

func (p *Person) SetName(name string) {
	p.Name = name
}

func (p *Person) GetName() string {
	return p.Name
}

func (p *person) WithAge(age int) *Person {
	pCopy := *p
	pCopy.age = age
	return &pCopy
}

func main() {
	fmt.Println("Hello")
}
