#define exit(x) mock_ptr->exit(x)
#define getpagesize() mock_ptr->getpagesize()
#define calloc(x, y) mock_ptr->calloc(x, y)
#define mprotect(x, y, z) mock_ptr->mprotect(x, y, z)

#define dift_log(x, ...) mock_ptr->dift_log(x)
#define next_block(x) mock_ptr->next_block(x)
#define alloc_hd_dirty_page() mock_ptr->alloc_hd_dirty_page()
#define dift_rec_enqueue(x) mock_ptr->dift_rec_enqueue(x)
#define kick_enqptr() mock_ptr->kick_enqptr()
#define wait_dift_analysis() mock_ptr->wait_dift_analysis()
#define gen_rt_finish_curr_block() mock_ptr->gen_rt_finish_curr_block()
#define gen_rt_get_next_enqptr() mock_ptr->gen_rt_get_next_enqptr()
#define gen_rt_enqueue_one_rec() mock_ptr->gen_rt_enqueue_one_rec()
#define gen_rt_enqueue_raddr() mock_ptr->gen_rt_enqueue_raddr()
#define gen_rt_enqueue_waddr() mock_ptr->gen_rt_enqueue_waddr()
