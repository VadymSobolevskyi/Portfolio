/*
* Vadym Sobolevskyi | 2026-11-04
*
* C# Script for the game on Unity engine. 
* Script controls movements of the player with "Arrow" keys and "WASD" keys.
 */

using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerController : MonoBehaviour
{
 // Speed at which the player moves.
 public float speed = 0; 

 // Rigidbody of the player.
 private Rigidbody rb1; 

 // Movement along X and Y axes.
 private float movementX;
 private float movementY;

 // Start is called before the first frame update.
 void Start()
    {
 // Get and store the Rigidbody component attached to the player.
        rb1 = GetComponent<Rigidbody>();
    }
 
 // This function is called when a move input is detected.
 void OnMove(InputValue movementValue)
    {
 // Convert the input value into a Vector2 for movement.
        Vector2 movementVector = movementValue.Get<Vector2>();

 // Store the X and Y components of the movement.
        movementX = movementVector.x; 
        movementY = movementVector.y; 
    }

 // FixedUpdate is called once per fixed frame-rate frame.
 void FixedUpdate() 
    {
 // Create a 3D movement vector using the X and Y inputs.
        Vector3 movement = new Vector3 (movementX, 0.0f, movementY);
    }
}