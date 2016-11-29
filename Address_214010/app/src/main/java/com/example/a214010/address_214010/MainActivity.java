package com.example.a214010.address_214010;

import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import java.io.File;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    AddressDB helper=new AddressDB(this);

    Button createbutton;
    Button updatebutton;
    Button readbutton;
    Button deletebutton;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        createbutton = (Button)findViewById(R.id.Createbutton);
        createbutton.setOnClickListener(this);
        readbutton = (Button)findViewById(R.id.Readbutton);
        readbutton.setOnClickListener(this);
        updatebutton = (Button)findViewById(R.id.Updatebutton);
        updatebutton.setOnClickListener(this);
        deletebutton = (Button)findViewById(R.id.Deletebutton);
        deletebutton.setOnClickListener(this);


    }


    public void onClick(View v) {
        if(v == createbutton) {
            Intent intent = new Intent(getApplication(), CreateActivity.class);
            startActivity(intent);
        }
        if(v == readbutton) {
            Intent intent = new Intent(getApplication(),ReadActivity.class);
            startActivity(intent);
        }
        if(v == updatebutton) {
            Intent intent = new Intent(getApplication(),UpdateActivity.class);
            startActivity(intent);
        }
        if(v == deletebutton) {
            Intent intent = new Intent(getApplication(),DeleteActivity.class);
            startActivity(intent);
        }

        /*AddressDB helper=new AddressDB(this);
        SQLiteDatabase database =helper.getWritableDatabase();

        ContentValues values=new ContentValues();
        values.put("Name","Test1");
        values.put("Age","Test1");
        values.put("Address","Test1");
        database.insert("address",null,values);
        database.close();*/
    }

    /*public void readdata(View view) {
        Intent intent = new Intent(getApplication(),ReadActivity.class);
        startActivity(intent);
    }
    public void updatedata(View view) {
        Intent intent = new Intent(getApplication(),ReadActivity.class);
        startActivity(intent);
    }
    public void deletedata(View view) {
        Intent intent = new Intent(getApplication(),ReadActivity.class);
        startActivity(intent);
    }*/
}
