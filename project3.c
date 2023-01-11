#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//---------------- Headers ----------------//

#include "User.h"
#include "Post.h"
#include "Post_Node.h"
#include "User_Node.h"
#include "User_List.h"
#include "Post_List.h"
#include "user_list_constructor.h"
#include "post_list_constructor.h"
#include "user_constructor.h"
#include "post_constructor.h"
#include "new_user.h"
#include "new_post.h"
#include "get_post.h"
#include "get_user.h"
#include "delete_post.h"
#include "like_post.h"
#include "print_user_posts.h"
#include "print_user.h"
#include "command_identyfier.h"
#include "get_dynamic_string.h"
#include "get_new_id.h"
#include "signup.h"
#include "postf.h"
#include "like.h"
#include "delete.h"
#include "info.h"
#include "find_user.h"
#include "login.h"
#include "logout.h"
#include "login_menu.h"
#include "user_menu.h"
#include "print_user_list.h"
#include "command_control.h"
#include "write_users_info_to_file.h"
#include "write_posts_info_to_file.h"

//---------------- defines ----------------//

#define MAX_COMMAND_LENGTH 100
#define INPUT_SEPARATOR ' '

//---------------- Structs ---------------- //

struct User;
struct Post;
struct Post_Node;
struct User_Node;
struct User_List;
struct Post_List;

// --------------- Constructors --------------- //

/*az constructors baraye meghdar_dehi struct estefade mikonim */

//---------------- Functions ---------------- //

int main()
{
    struct User_List user_list;
    struct Post_List post_list;

    user_list_constructor(&user_list);
    post_list_constructor(&post_list);

    struct User *current_user = NULL;

    while (true)
    {
        if (command_control(&post_list, &user_list, &current_user) == false)
        {
            break;
        }
    }

    write_users_info_to_file(&user_list);
    write_posts_info_to_file(&user_list, &post_list);

    return 0;
}
