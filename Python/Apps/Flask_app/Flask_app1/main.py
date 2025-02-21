
from flask import Flask, render_template, redirect, url_for, flash, request
from flask_sqlalchemy import SQLAlchemy
from flask_login import  LoginManager, UserMixin, login_required, login_user, logout_user, current_user
from werkzeug.security import generate_password_hash, check_password_hash
from forms import LoginForm, RegistrationForm 


app = Flask(__name__)
app.config['SECRET_KEY'] = 'supergawonou'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False


db = SQLAlchemy(app)
login_manager = LoginManager()
login_manager.init_app(app)
login_manager.login

from models import User

@app.route("/")
def index():
    
    return render_template('index.html') 
    


@app.route("/about")
def about():
    #messages = f"\n\nMessage from about page"
    return render_template('about.html') 



@app.route("/services")
def services():
    #messages = f"\n\nMessage from about page"
    return render_template('services.html') 


@app.route("/contact")
def contact():
    #messages = f"\n\nMessage from about page"
    return render_template('contact.html') 


@app.route("/user/<string:name>")
def user(name):
    messages = f"\n\nMessage from user name's {name}"
    return messages




if __name__ == "__main__":
    app.run(debug=True)
