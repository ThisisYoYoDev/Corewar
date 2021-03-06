// Code generated by entc, DO NOT EDIT.

package champ

import (
	"Corewar_Api/ent/predicate"

	"entgo.io/ent/dialect/sql"
	"github.com/google/uuid"
)

// ID filters vertices based on their ID field.
func ID(id uuid.UUID) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldID), id))
	})
}

// IDEQ applies the EQ predicate on the ID field.
func IDEQ(id uuid.UUID) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldID), id))
	})
}

// IDNEQ applies the NEQ predicate on the ID field.
func IDNEQ(id uuid.UUID) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.NEQ(s.C(FieldID), id))
	})
}

// IDIn applies the In predicate on the ID field.
func IDIn(ids ...uuid.UUID) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(ids) == 0 {
			s.Where(sql.False())
			return
		}
		v := make([]interface{}, len(ids))
		for i := range v {
			v[i] = ids[i]
		}
		s.Where(sql.In(s.C(FieldID), v...))
	})
}

// IDNotIn applies the NotIn predicate on the ID field.
func IDNotIn(ids ...uuid.UUID) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(ids) == 0 {
			s.Where(sql.False())
			return
		}
		v := make([]interface{}, len(ids))
		for i := range v {
			v[i] = ids[i]
		}
		s.Where(sql.NotIn(s.C(FieldID), v...))
	})
}

// IDGT applies the GT predicate on the ID field.
func IDGT(id uuid.UUID) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GT(s.C(FieldID), id))
	})
}

// IDGTE applies the GTE predicate on the ID field.
func IDGTE(id uuid.UUID) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GTE(s.C(FieldID), id))
	})
}

// IDLT applies the LT predicate on the ID field.
func IDLT(id uuid.UUID) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LT(s.C(FieldID), id))
	})
}

// IDLTE applies the LTE predicate on the ID field.
func IDLTE(id uuid.UUID) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LTE(s.C(FieldID), id))
	})
}

// Name applies equality check predicate on the "name" field. It's identical to NameEQ.
func Name(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldName), v))
	})
}

// Path applies equality check predicate on the "path" field. It's identical to PathEQ.
func Path(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldPath), v))
	})
}

// NumberOfVictory applies equality check predicate on the "number_of_victory" field. It's identical to NumberOfVictoryEQ.
func NumberOfVictory(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldNumberOfVictory), v))
	})
}

// NumberOfDefeats applies equality check predicate on the "number_of_defeats" field. It's identical to NumberOfDefeatsEQ.
func NumberOfDefeats(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldNumberOfDefeats), v))
	})
}

// NameEQ applies the EQ predicate on the "name" field.
func NameEQ(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldName), v))
	})
}

// NameNEQ applies the NEQ predicate on the "name" field.
func NameNEQ(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.NEQ(s.C(FieldName), v))
	})
}

// NameIn applies the In predicate on the "name" field.
func NameIn(vs ...string) predicate.Champ {
	v := make([]interface{}, len(vs))
	for i := range v {
		v[i] = vs[i]
	}
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(v) == 0 {
			s.Where(sql.False())
			return
		}
		s.Where(sql.In(s.C(FieldName), v...))
	})
}

// NameNotIn applies the NotIn predicate on the "name" field.
func NameNotIn(vs ...string) predicate.Champ {
	v := make([]interface{}, len(vs))
	for i := range v {
		v[i] = vs[i]
	}
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(v) == 0 {
			s.Where(sql.False())
			return
		}
		s.Where(sql.NotIn(s.C(FieldName), v...))
	})
}

// NameGT applies the GT predicate on the "name" field.
func NameGT(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GT(s.C(FieldName), v))
	})
}

// NameGTE applies the GTE predicate on the "name" field.
func NameGTE(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GTE(s.C(FieldName), v))
	})
}

// NameLT applies the LT predicate on the "name" field.
func NameLT(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LT(s.C(FieldName), v))
	})
}

// NameLTE applies the LTE predicate on the "name" field.
func NameLTE(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LTE(s.C(FieldName), v))
	})
}

// NameContains applies the Contains predicate on the "name" field.
func NameContains(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.Contains(s.C(FieldName), v))
	})
}

// NameHasPrefix applies the HasPrefix predicate on the "name" field.
func NameHasPrefix(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.HasPrefix(s.C(FieldName), v))
	})
}

// NameHasSuffix applies the HasSuffix predicate on the "name" field.
func NameHasSuffix(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.HasSuffix(s.C(FieldName), v))
	})
}

// NameEqualFold applies the EqualFold predicate on the "name" field.
func NameEqualFold(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EqualFold(s.C(FieldName), v))
	})
}

// NameContainsFold applies the ContainsFold predicate on the "name" field.
func NameContainsFold(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.ContainsFold(s.C(FieldName), v))
	})
}

// PathEQ applies the EQ predicate on the "path" field.
func PathEQ(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldPath), v))
	})
}

// PathNEQ applies the NEQ predicate on the "path" field.
func PathNEQ(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.NEQ(s.C(FieldPath), v))
	})
}

// PathIn applies the In predicate on the "path" field.
func PathIn(vs ...string) predicate.Champ {
	v := make([]interface{}, len(vs))
	for i := range v {
		v[i] = vs[i]
	}
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(v) == 0 {
			s.Where(sql.False())
			return
		}
		s.Where(sql.In(s.C(FieldPath), v...))
	})
}

// PathNotIn applies the NotIn predicate on the "path" field.
func PathNotIn(vs ...string) predicate.Champ {
	v := make([]interface{}, len(vs))
	for i := range v {
		v[i] = vs[i]
	}
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(v) == 0 {
			s.Where(sql.False())
			return
		}
		s.Where(sql.NotIn(s.C(FieldPath), v...))
	})
}

// PathGT applies the GT predicate on the "path" field.
func PathGT(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GT(s.C(FieldPath), v))
	})
}

// PathGTE applies the GTE predicate on the "path" field.
func PathGTE(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GTE(s.C(FieldPath), v))
	})
}

// PathLT applies the LT predicate on the "path" field.
func PathLT(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LT(s.C(FieldPath), v))
	})
}

// PathLTE applies the LTE predicate on the "path" field.
func PathLTE(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LTE(s.C(FieldPath), v))
	})
}

// PathContains applies the Contains predicate on the "path" field.
func PathContains(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.Contains(s.C(FieldPath), v))
	})
}

// PathHasPrefix applies the HasPrefix predicate on the "path" field.
func PathHasPrefix(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.HasPrefix(s.C(FieldPath), v))
	})
}

// PathHasSuffix applies the HasSuffix predicate on the "path" field.
func PathHasSuffix(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.HasSuffix(s.C(FieldPath), v))
	})
}

// PathEqualFold applies the EqualFold predicate on the "path" field.
func PathEqualFold(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EqualFold(s.C(FieldPath), v))
	})
}

// PathContainsFold applies the ContainsFold predicate on the "path" field.
func PathContainsFold(v string) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.ContainsFold(s.C(FieldPath), v))
	})
}

// NumberOfVictoryEQ applies the EQ predicate on the "number_of_victory" field.
func NumberOfVictoryEQ(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldNumberOfVictory), v))
	})
}

// NumberOfVictoryNEQ applies the NEQ predicate on the "number_of_victory" field.
func NumberOfVictoryNEQ(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.NEQ(s.C(FieldNumberOfVictory), v))
	})
}

// NumberOfVictoryIn applies the In predicate on the "number_of_victory" field.
func NumberOfVictoryIn(vs ...int) predicate.Champ {
	v := make([]interface{}, len(vs))
	for i := range v {
		v[i] = vs[i]
	}
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(v) == 0 {
			s.Where(sql.False())
			return
		}
		s.Where(sql.In(s.C(FieldNumberOfVictory), v...))
	})
}

// NumberOfVictoryNotIn applies the NotIn predicate on the "number_of_victory" field.
func NumberOfVictoryNotIn(vs ...int) predicate.Champ {
	v := make([]interface{}, len(vs))
	for i := range v {
		v[i] = vs[i]
	}
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(v) == 0 {
			s.Where(sql.False())
			return
		}
		s.Where(sql.NotIn(s.C(FieldNumberOfVictory), v...))
	})
}

// NumberOfVictoryGT applies the GT predicate on the "number_of_victory" field.
func NumberOfVictoryGT(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GT(s.C(FieldNumberOfVictory), v))
	})
}

// NumberOfVictoryGTE applies the GTE predicate on the "number_of_victory" field.
func NumberOfVictoryGTE(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GTE(s.C(FieldNumberOfVictory), v))
	})
}

// NumberOfVictoryLT applies the LT predicate on the "number_of_victory" field.
func NumberOfVictoryLT(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LT(s.C(FieldNumberOfVictory), v))
	})
}

// NumberOfVictoryLTE applies the LTE predicate on the "number_of_victory" field.
func NumberOfVictoryLTE(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LTE(s.C(FieldNumberOfVictory), v))
	})
}

// NumberOfDefeatsEQ applies the EQ predicate on the "number_of_defeats" field.
func NumberOfDefeatsEQ(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.EQ(s.C(FieldNumberOfDefeats), v))
	})
}

// NumberOfDefeatsNEQ applies the NEQ predicate on the "number_of_defeats" field.
func NumberOfDefeatsNEQ(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.NEQ(s.C(FieldNumberOfDefeats), v))
	})
}

// NumberOfDefeatsIn applies the In predicate on the "number_of_defeats" field.
func NumberOfDefeatsIn(vs ...int) predicate.Champ {
	v := make([]interface{}, len(vs))
	for i := range v {
		v[i] = vs[i]
	}
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(v) == 0 {
			s.Where(sql.False())
			return
		}
		s.Where(sql.In(s.C(FieldNumberOfDefeats), v...))
	})
}

// NumberOfDefeatsNotIn applies the NotIn predicate on the "number_of_defeats" field.
func NumberOfDefeatsNotIn(vs ...int) predicate.Champ {
	v := make([]interface{}, len(vs))
	for i := range v {
		v[i] = vs[i]
	}
	return predicate.Champ(func(s *sql.Selector) {
		// if not arguments were provided, append the FALSE constants,
		// since we can't apply "IN ()". This will make this predicate falsy.
		if len(v) == 0 {
			s.Where(sql.False())
			return
		}
		s.Where(sql.NotIn(s.C(FieldNumberOfDefeats), v...))
	})
}

// NumberOfDefeatsGT applies the GT predicate on the "number_of_defeats" field.
func NumberOfDefeatsGT(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GT(s.C(FieldNumberOfDefeats), v))
	})
}

// NumberOfDefeatsGTE applies the GTE predicate on the "number_of_defeats" field.
func NumberOfDefeatsGTE(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.GTE(s.C(FieldNumberOfDefeats), v))
	})
}

// NumberOfDefeatsLT applies the LT predicate on the "number_of_defeats" field.
func NumberOfDefeatsLT(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LT(s.C(FieldNumberOfDefeats), v))
	})
}

// NumberOfDefeatsLTE applies the LTE predicate on the "number_of_defeats" field.
func NumberOfDefeatsLTE(v int) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s.Where(sql.LTE(s.C(FieldNumberOfDefeats), v))
	})
}

// And groups predicates with the AND operator between them.
func And(predicates ...predicate.Champ) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s1 := s.Clone().SetP(nil)
		for _, p := range predicates {
			p(s1)
		}
		s.Where(s1.P())
	})
}

// Or groups predicates with the OR operator between them.
func Or(predicates ...predicate.Champ) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		s1 := s.Clone().SetP(nil)
		for i, p := range predicates {
			if i > 0 {
				s1.Or()
			}
			p(s1)
		}
		s.Where(s1.P())
	})
}

// Not applies the not operator on the given predicate.
func Not(p predicate.Champ) predicate.Champ {
	return predicate.Champ(func(s *sql.Selector) {
		p(s.Not())
	})
}
