// Code generated by entc, DO NOT EDIT.

package champ

import (
	"github.com/google/uuid"
)

const (
	// Label holds the string label denoting the champ type in the database.
	Label = "champ"
	// FieldID holds the string denoting the id field in the database.
	FieldID = "id"
	// FieldName holds the string denoting the name field in the database.
	FieldName = "name"
	// FieldPath holds the string denoting the path field in the database.
	FieldPath = "path"
	// FieldNumberOfVictory holds the string denoting the number_of_victory field in the database.
	FieldNumberOfVictory = "number_of_victory"
	// FieldNumberOfDefeats holds the string denoting the number_of_defeats field in the database.
	FieldNumberOfDefeats = "number_of_defeats"
	// Table holds the table name of the champ in the database.
	Table = "champs"
)

// Columns holds all SQL columns for champ fields.
var Columns = []string{
	FieldID,
	FieldName,
	FieldPath,
	FieldNumberOfVictory,
	FieldNumberOfDefeats,
}

// ValidColumn reports if the column name is valid (part of the table columns).
func ValidColumn(column string) bool {
	for i := range Columns {
		if column == Columns[i] {
			return true
		}
	}
	return false
}

var (
	// NameValidator is a validator for the "name" field. It is called by the builders before save.
	NameValidator func(string) error
	// PathValidator is a validator for the "path" field. It is called by the builders before save.
	PathValidator func(string) error
	// DefaultNumberOfVictory holds the default value on creation for the "number_of_victory" field.
	DefaultNumberOfVictory int
	// NumberOfVictoryValidator is a validator for the "number_of_victory" field. It is called by the builders before save.
	NumberOfVictoryValidator func(int) error
	// DefaultNumberOfDefeats holds the default value on creation for the "number_of_defeats" field.
	DefaultNumberOfDefeats int
	// NumberOfDefeatsValidator is a validator for the "number_of_defeats" field. It is called by the builders before save.
	NumberOfDefeatsValidator func(int) error
	// DefaultID holds the default value on creation for the "id" field.
	DefaultID func() uuid.UUID
)