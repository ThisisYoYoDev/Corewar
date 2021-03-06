// Code generated by entc, DO NOT EDIT.

package ent

import (
	"Corewar_Api/ent/champ"
	"context"
	"errors"
	"fmt"

	"entgo.io/ent/dialect/sql/sqlgraph"
	"entgo.io/ent/schema/field"
	"github.com/google/uuid"
)

// ChampCreate is the builder for creating a Champ entity.
type ChampCreate struct {
	config
	mutation *ChampMutation
	hooks    []Hook
}

// SetName sets the "name" field.
func (cc *ChampCreate) SetName(s string) *ChampCreate {
	cc.mutation.SetName(s)
	return cc
}

// SetPath sets the "path" field.
func (cc *ChampCreate) SetPath(s string) *ChampCreate {
	cc.mutation.SetPath(s)
	return cc
}

// SetNumberOfVictory sets the "number_of_victory" field.
func (cc *ChampCreate) SetNumberOfVictory(i int) *ChampCreate {
	cc.mutation.SetNumberOfVictory(i)
	return cc
}

// SetNillableNumberOfVictory sets the "number_of_victory" field if the given value is not nil.
func (cc *ChampCreate) SetNillableNumberOfVictory(i *int) *ChampCreate {
	if i != nil {
		cc.SetNumberOfVictory(*i)
	}
	return cc
}

// SetNumberOfDefeats sets the "number_of_defeats" field.
func (cc *ChampCreate) SetNumberOfDefeats(i int) *ChampCreate {
	cc.mutation.SetNumberOfDefeats(i)
	return cc
}

// SetNillableNumberOfDefeats sets the "number_of_defeats" field if the given value is not nil.
func (cc *ChampCreate) SetNillableNumberOfDefeats(i *int) *ChampCreate {
	if i != nil {
		cc.SetNumberOfDefeats(*i)
	}
	return cc
}

// SetID sets the "id" field.
func (cc *ChampCreate) SetID(u uuid.UUID) *ChampCreate {
	cc.mutation.SetID(u)
	return cc
}

// Mutation returns the ChampMutation object of the builder.
func (cc *ChampCreate) Mutation() *ChampMutation {
	return cc.mutation
}

// Save creates the Champ in the database.
func (cc *ChampCreate) Save(ctx context.Context) (*Champ, error) {
	var (
		err  error
		node *Champ
	)
	cc.defaults()
	if len(cc.hooks) == 0 {
		if err = cc.check(); err != nil {
			return nil, err
		}
		node, err = cc.sqlSave(ctx)
	} else {
		var mut Mutator = MutateFunc(func(ctx context.Context, m Mutation) (Value, error) {
			mutation, ok := m.(*ChampMutation)
			if !ok {
				return nil, fmt.Errorf("unexpected mutation type %T", m)
			}
			if err = cc.check(); err != nil {
				return nil, err
			}
			cc.mutation = mutation
			node, err = cc.sqlSave(ctx)
			mutation.done = true
			return node, err
		})
		for i := len(cc.hooks) - 1; i >= 0; i-- {
			mut = cc.hooks[i](mut)
		}
		if _, err := mut.Mutate(ctx, cc.mutation); err != nil {
			return nil, err
		}
	}
	return node, err
}

// SaveX calls Save and panics if Save returns an error.
func (cc *ChampCreate) SaveX(ctx context.Context) *Champ {
	v, err := cc.Save(ctx)
	if err != nil {
		panic(err)
	}
	return v
}

// defaults sets the default values of the builder before save.
func (cc *ChampCreate) defaults() {
	if _, ok := cc.mutation.NumberOfVictory(); !ok {
		v := champ.DefaultNumberOfVictory
		cc.mutation.SetNumberOfVictory(v)
	}
	if _, ok := cc.mutation.NumberOfDefeats(); !ok {
		v := champ.DefaultNumberOfDefeats
		cc.mutation.SetNumberOfDefeats(v)
	}
	if _, ok := cc.mutation.ID(); !ok {
		v := champ.DefaultID()
		cc.mutation.SetID(v)
	}
}

// check runs all checks and user-defined validators on the builder.
func (cc *ChampCreate) check() error {
	if _, ok := cc.mutation.Name(); !ok {
		return &ValidationError{Name: "name", err: errors.New("ent: missing required field \"name\"")}
	}
	if v, ok := cc.mutation.Name(); ok {
		if err := champ.NameValidator(v); err != nil {
			return &ValidationError{Name: "name", err: fmt.Errorf("ent: validator failed for field \"name\": %w", err)}
		}
	}
	if _, ok := cc.mutation.Path(); !ok {
		return &ValidationError{Name: "path", err: errors.New("ent: missing required field \"path\"")}
	}
	if v, ok := cc.mutation.Path(); ok {
		if err := champ.PathValidator(v); err != nil {
			return &ValidationError{Name: "path", err: fmt.Errorf("ent: validator failed for field \"path\": %w", err)}
		}
	}
	if _, ok := cc.mutation.NumberOfVictory(); !ok {
		return &ValidationError{Name: "number_of_victory", err: errors.New("ent: missing required field \"number_of_victory\"")}
	}
	if v, ok := cc.mutation.NumberOfVictory(); ok {
		if err := champ.NumberOfVictoryValidator(v); err != nil {
			return &ValidationError{Name: "number_of_victory", err: fmt.Errorf("ent: validator failed for field \"number_of_victory\": %w", err)}
		}
	}
	if _, ok := cc.mutation.NumberOfDefeats(); !ok {
		return &ValidationError{Name: "number_of_defeats", err: errors.New("ent: missing required field \"number_of_defeats\"")}
	}
	if v, ok := cc.mutation.NumberOfDefeats(); ok {
		if err := champ.NumberOfDefeatsValidator(v); err != nil {
			return &ValidationError{Name: "number_of_defeats", err: fmt.Errorf("ent: validator failed for field \"number_of_defeats\": %w", err)}
		}
	}
	return nil
}

func (cc *ChampCreate) sqlSave(ctx context.Context) (*Champ, error) {
	_node, _spec := cc.createSpec()
	if err := sqlgraph.CreateNode(ctx, cc.driver, _spec); err != nil {
		if cerr, ok := isSQLConstraintError(err); ok {
			err = cerr
		}
		return nil, err
	}
	return _node, nil
}

func (cc *ChampCreate) createSpec() (*Champ, *sqlgraph.CreateSpec) {
	var (
		_node = &Champ{config: cc.config}
		_spec = &sqlgraph.CreateSpec{
			Table: champ.Table,
			ID: &sqlgraph.FieldSpec{
				Type:   field.TypeUUID,
				Column: champ.FieldID,
			},
		}
	)
	if id, ok := cc.mutation.ID(); ok {
		_node.ID = id
		_spec.ID.Value = id
	}
	if value, ok := cc.mutation.Name(); ok {
		_spec.Fields = append(_spec.Fields, &sqlgraph.FieldSpec{
			Type:   field.TypeString,
			Value:  value,
			Column: champ.FieldName,
		})
		_node.Name = value
	}
	if value, ok := cc.mutation.Path(); ok {
		_spec.Fields = append(_spec.Fields, &sqlgraph.FieldSpec{
			Type:   field.TypeString,
			Value:  value,
			Column: champ.FieldPath,
		})
		_node.Path = value
	}
	if value, ok := cc.mutation.NumberOfVictory(); ok {
		_spec.Fields = append(_spec.Fields, &sqlgraph.FieldSpec{
			Type:   field.TypeInt,
			Value:  value,
			Column: champ.FieldNumberOfVictory,
		})
		_node.NumberOfVictory = value
	}
	if value, ok := cc.mutation.NumberOfDefeats(); ok {
		_spec.Fields = append(_spec.Fields, &sqlgraph.FieldSpec{
			Type:   field.TypeInt,
			Value:  value,
			Column: champ.FieldNumberOfDefeats,
		})
		_node.NumberOfDefeats = value
	}
	return _node, _spec
}

// ChampCreateBulk is the builder for creating many Champ entities in bulk.
type ChampCreateBulk struct {
	config
	builders []*ChampCreate
}

// Save creates the Champ entities in the database.
func (ccb *ChampCreateBulk) Save(ctx context.Context) ([]*Champ, error) {
	specs := make([]*sqlgraph.CreateSpec, len(ccb.builders))
	nodes := make([]*Champ, len(ccb.builders))
	mutators := make([]Mutator, len(ccb.builders))
	for i := range ccb.builders {
		func(i int, root context.Context) {
			builder := ccb.builders[i]
			builder.defaults()
			var mut Mutator = MutateFunc(func(ctx context.Context, m Mutation) (Value, error) {
				mutation, ok := m.(*ChampMutation)
				if !ok {
					return nil, fmt.Errorf("unexpected mutation type %T", m)
				}
				if err := builder.check(); err != nil {
					return nil, err
				}
				builder.mutation = mutation
				nodes[i], specs[i] = builder.createSpec()
				var err error
				if i < len(mutators)-1 {
					_, err = mutators[i+1].Mutate(root, ccb.builders[i+1].mutation)
				} else {
					// Invoke the actual operation on the latest mutation in the chain.
					if err = sqlgraph.BatchCreate(ctx, ccb.driver, &sqlgraph.BatchCreateSpec{Nodes: specs}); err != nil {
						if cerr, ok := isSQLConstraintError(err); ok {
							err = cerr
						}
					}
				}
				mutation.done = true
				if err != nil {
					return nil, err
				}
				return nodes[i], nil
			})
			for i := len(builder.hooks) - 1; i >= 0; i-- {
				mut = builder.hooks[i](mut)
			}
			mutators[i] = mut
		}(i, ctx)
	}
	if len(mutators) > 0 {
		if _, err := mutators[0].Mutate(ctx, ccb.builders[0].mutation); err != nil {
			return nil, err
		}
	}
	return nodes, nil
}

// SaveX is like Save, but panics if an error occurs.
func (ccb *ChampCreateBulk) SaveX(ctx context.Context) []*Champ {
	v, err := ccb.Save(ctx)
	if err != nil {
		panic(err)
	}
	return v
}
