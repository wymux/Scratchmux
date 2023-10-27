package main

import "fmt"

type Character struct {
	Name    string
	Class   string
	Level   int
	HitDice int
}

func (c Character) PrintInfo() {
	fmt.Printf("Name: %s\nClass: %s\nLevel: %d\nHit Dice: %d\n",
		c.Name, c.Class, c.Level, c.HitDice)
}

func main() {
	gandalf := Character{
		Name:    "Gandalf",
		Class:   "Wizard",
		Level:   10,
		HitDice: 6,
	}

	gandalf.PrintInfo()
}
