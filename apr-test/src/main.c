#include <stdio.h>
#include <stdlib.h>
#include "apr.h"
#include "apr_pools.h"
#include "apr_thread_rwlock.h"


apr_pool_t* qkd_pool = NULL;

int main()
{
	apr_status_t ret = 0;
	apr_thread_rwlock_t* handle_rwlock;

	apr_initialize();
	apr_pool_create(&qkd_pool, NULL);

	ret = apr_thread_rwlock_create(&handle_rwlock, qkd_pool);
	if (ret != APR_SUCCESS)
	{
		printf("ERROR: apr_thread_rwlock_create failed!\n");
		return -1;
	}

	ret = apr_thread_rwlock_wrlock(handle_rwlock);
	ret = apr_thread_rwlock_rdlock(handle_rwlock);
	apr_thread_rwlock_unlock(handle_rwlock);
	apr_thread_rwlock_unlock(handle_rwlock);

	apr_thread_rwlock_rdlock(handle_rwlock);
	apr_thread_rwlock_unlock(handle_rwlock);

	return 0;
}
