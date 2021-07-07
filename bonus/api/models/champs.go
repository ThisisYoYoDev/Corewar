package models

import (
	"Corewar_Api/database"
	"Corewar_Api/ent"
	"Corewar_Api/ent/champ"
	"github.com/google/uuid"
)

type DataChamps struct {
	Name				string `json:"name"`
	DataCode			string `json:"data_code"`
	Path				string
	Victory				int
	Defeats				int
	Id					uuid.UUID
}

func CreateChamps(data DataChamps) (*ent.Champ, error) {
	myUser, err := database.Db.Def.Champ.
		Create().
		SetName(data.Name).
		SetPath(data.Path).
		Save(database.Db.Ctx)
	if err != nil {
		return nil, err
	}
	return myUser, nil
}

func GetAllChamps() ([]*ent.Champ, error) {
	champs, err := database.Db.Def.Champ.
		Query().
		All(database.Db.Ctx)
	if err != nil {
		return nil, err
	}
	return champs, nil
}

func GetOneChamps(name string) (*ent.Champ, error) {
	champs, err := database.Db.Def.Champ.
		Query().
		Where(
			champ.Name(name)).
		Only(database.Db.Ctx)
	if err != nil {
		return nil, err
	}
	return champs, nil
}

func AddVictory(victory int, id uuid.UUID) error {
	victory = victory + 1
	_, err := database.Db.Def.Champ.
		UpdateOneID(id).
		SetNumberOfVictory(victory).
		Save(database.Db.Ctx)
	if err != nil {
		return err
	}
	return nil
}

func AddDefeats(defeats int, id uuid.UUID) error {
	defeats = defeats + 1
	_, err := database.Db.Def.Champ.
		UpdateOneID(id).
		SetNumberOfDefeats(defeats).
		Save(database.Db.Ctx)
	if err != nil {
		return err
	}
	return nil
}