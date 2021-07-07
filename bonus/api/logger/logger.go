package logger

import "go.uber.org/zap"

var Log *zap.SugaredLogger = nil

func CreateNewLogger() error {
	log, err := zap.NewDevelopment()
	if err != nil {
		return err
	}
	Log = log.Sugar()
	return nil
}