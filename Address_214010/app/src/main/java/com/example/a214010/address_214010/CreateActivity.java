package com.example.a214010.address_214010;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class CreateActivity extends AppCompatActivity {

    EditText nametext;
    EditText agetext;
    EditText addresstext;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.create);

        nametext = (EditText)findViewById(R.id.nameedit);
        agetext = (EditText)findViewById(R.id.ageedit);
        addresstext = (EditText)findViewById(R.id.addressedit);
    }

    public void createdata(View view){
        AddressDB helper = new AddressDB(this);
        SQLiteDatabase database = helper.getWritableDatabase();

        ContentValues values = new ContentValues();

        values.put("Name",""+(nametext.getText().toString()));
        values.put("Age",""+(agetext.getText().toString()));
        values.put("Address",""+(addresstext.getText().toString()));

        database.insert("address",null,values);

        database.close();
    }
    public void back(View view){
        Intent intent = new Intent(getApplication(),MainActivity.class);
        startActivity(intent);
    }
}
