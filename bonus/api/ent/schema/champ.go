package schema

import (
	"entgo.io/ent"
	"entgo.io/ent/schema/field"
	"github.com/google/uuid"
)

// Champ holds the schema definition for the Champ entity.
type Champ struct {
	ent.Schema
}

// Fields of the Champ.
func (Champ) Fields() []ent.Field {
	return []ent.Field{
		field.UUID("id", uuid.UUID{}).Default(uuid.New),
		field.String("name").NotEmpty().Unique(),
		field.String("path").NotEmpty().Unique(),
		field.Int("number_of_victory").Min(0).Default(0),
		field.Int("number_of_defeats").Min(0).Default(0),
	}
}

// Edges of the Champ.
func (Champ) Edges() []ent.Edge {
	return nil
}
