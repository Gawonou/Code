from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, SubmitField
from wtforms.validators import InputRequired, Length, EqualTo

class LoginForm(FlaskForm):
    username = StringField('Nom d\'utilisateur', validators=[InputRequired(), Length(min=4, max=20)])
    password = PasswordField('Mot de passe', validators=[InputRequired()])
    submit = SubmitField('Se connecter')

class RegistrationForm(FlaskForm):
    username = StringField('Nom d\'utilisateur', validators=[InputRequired(), Length(min=4, max=20)])
    password = PasswordField('Mot de passe', validators=[InputRequired(), Length(min=6)])
    confirm_password = PasswordField('Confirmez le mot de passe', validators=[InputRequired(), EqualTo('password')])
    submit = SubmitField('S\'inscrire')
